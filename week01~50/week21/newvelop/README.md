# 10999. 구간 합 구하기 2

[링크](https://www.acmicpc.net/problem/10999)


## 설계

### 시간 복잡도

세그먼트 트리를 구현할 경우, O(logN)의 시간복잡도로 조회할 수 있다. 하지만 명령어 개수가 K 개 일 경우 O(KlogN)의 복잡도가 된다.연산의 수를 최대한 줄이기 위해 lazy propagation으로 수행한다.


### 공간 복잡도

세그먼트 트리에 배열 N 을 저장하고, N*4 사이즈의 배열 2개를 저정하기 때문에 총 O(N)의 공간 복잡도를 사용한다.

## 정리
처음에는 그냥 세그먼트 트리를 이용해서 구현하려고 했다.

```java
   public static class Segment {
       Tree[] trees;
       long[] arr;

       public Segment(long[] arr) {
           this.trees = new Tree[arr.length * 4];
           this.arr = arr;
           init(1, 0, arr.length - 1);
       }

       public Tree init(int index, int left, int right) {
           if (left == right) {
               return trees[index] = new Tree(arr[left]);
           }
           int mid = (left + right) / 2;
           Tree leftTree = init(index * 2, left, mid);
           Tree rightTree = init(index * 2 + 1, mid + 1, right);
           trees[index] = new Tree();
           trees[index].sum = leftTree.sum + rightTree.sum;
           return trees[index];
       }

       public void updateTree(long arrLeft, long arrRight, long value) {
           update(1, 0, arr.length - 1, (int) arrLeft - 1, (int) arrRight - 1, value);
       }

       private void update(int nodeIndex, int nodeLeft, int nodeRight, int arrLeft, int arrRight, long value) {
           if (arrLeft > nodeRight || arrRight < nodeLeft) {
               return;
           }

           if (nodeLeft == nodeRight) {
               arr[nodeLeft] += value;
               trees[nodeIndex].sum += value;
               return;
           }

           int mid = (nodeLeft + nodeRight) / 2;
           update(nodeIndex * 2, nodeLeft, mid, arrLeft, arrRight, value);
           update(nodeIndex * 2 + 1, mid + 1, nodeRight, arrLeft, arrRight, value);
           int leftMax = Math.max(nodeLeft, arrLeft);
           int rightMin = Math.min(nodeRight, arrRight);
           trees[nodeIndex].sum += ((rightMin - leftMax + 1) * value);
           return;
       }

       public Tree find(long arrLeft, long arrRight) {
           return find(1, 0, arr.length - 1, (int) arrLeft - 1, (int) arrRight - 1);
       }

       private Tree find(int nodeIndex, int nodeLeft, int nodeRight, int arrLeft, int arrRight) {
           if (nodeLeft > arrRight || nodeRight < arrLeft) {
               return new Tree(0);
           }

           if (nodeLeft == nodeRight) {
               return trees[nodeIndex];
           }

           if (arrLeft <= nodeLeft && arrRight >= nodeRight) {
               return trees[nodeIndex];
           } else {
               int mid = (nodeLeft + nodeRight) / 2;
               Tree leftTree = find(nodeIndex * 2, nodeLeft, mid, arrLeft, arrRight);
               Tree rightTree = find(nodeIndex * 2 + 1, mid + 1, nodeRight, arrLeft, arrRight);
               Tree result = new Tree();
               result.sum = leftTree.sum + rightTree.sum;
               return result;
           }
       }
   }
```
하지만 시간 초과가 났다


```java
public class Main010999 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long[] input = Arrays.stream(br.readLine().split(" ")).mapToLong(Long::parseLong).toArray();
        long[] arr = new long[(int) input[0]];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = Long.parseLong(br.readLine());
        }

        Segment segment = new Segment(arr);

        for (int i = 0; i < input[1] + input[2]; i++) {
            long[] temp = Arrays.stream(br.readLine().split(" ")).mapToLong(Long::parseLong).toArray();
            if (temp[0] == 1L) {
                segment.updateTree(temp[1], temp[2], temp[3]);
            } else {
                System.out.println(segment.find(temp[1], temp[2]));
            }
        }
    }

    public static class Segment {
        long[] trees;
        long[] arr;
        long[] lazyArr;

        public Segment(long[] arr) {
            this.trees = new long[arr.length * 4];
            this.arr = arr;
            this.lazyArr = new long[arr.length * 4];
            init(1, 0, arr.length - 1);
        }

        public long init(int index, int left, int right) {
            if (left == right) {
                return trees[index] = arr[left];
            }
            int mid = (left + right) / 2;
            return trees[index] = init(index * 2, left, mid) + init(index * 2 + 1, mid + 1, right);
        }

        public void updateTree(long arrLeft, long arrRight, long value) {
            update(1, 0, arr.length - 1, (int) arrLeft - 1, (int) arrRight - 1, value);
        }

        public void propagate(int nodeIndex, int left, int right) {
            if (lazyArr[nodeIndex] != 0L) {
                if (left != right) {
                    lazyArr[nodeIndex * 2] += lazyArr[nodeIndex];
                    lazyArr[nodeIndex * 2 + 1] += lazyArr[nodeIndex];
                }
                trees[nodeIndex] += (lazyArr[nodeIndex] * (right - left + 1));
                lazyArr[nodeIndex] = 0L;
            }
        }

        private void update(int nodeIndex, int nodeLeft, int nodeRight, int arrLeft, int arrRight, long value) {
            propagate(nodeIndex, nodeLeft, nodeRight);

            // 범위 밖이면 계산할 필요가 없음 패스
            if (arrLeft > nodeRight || arrRight < nodeLeft) {
                return;
            }

            // 범위 안에 전부 포함하면 propagation 수행후 더이상 업데이트 하지 않음
            if (arrLeft <= nodeLeft && nodeRight <= arrRight) {
                lazyArr[nodeIndex] = value;
                propagate(nodeIndex, nodeLeft, nodeRight);
                return;
            }

            int mid = (nodeLeft + nodeRight) / 2;
            update(nodeIndex * 2, nodeLeft, mid, arrLeft, arrRight, value);
            update(nodeIndex * 2 + 1, mid + 1, nodeRight, arrLeft, arrRight, value);
            trees[nodeIndex] = trees[nodeIndex * 2] + trees[nodeIndex * 2 + 1];
        }

        public long find(long arrLeft, long arrRight) {
            return find(1, 0, arr.length - 1, (int) arrLeft - 1, (int) arrRight - 1);
        }

        private long find(int nodeIndex, int nodeLeft, int nodeRight, int arrLeft, int arrRight) {
            propagate(nodeIndex, nodeLeft, nodeRight);

            if (nodeLeft > arrRight || nodeRight < arrLeft) {
                return 0L;
            }

            if (nodeLeft == nodeRight) {
                return trees[nodeIndex];
            }

            if (arrLeft <= nodeLeft && arrRight >= nodeRight) {
                return trees[nodeIndex];
            } else {
                int mid = (nodeLeft + nodeRight) / 2;
                long leftTree = find(nodeIndex * 2, nodeLeft, mid, arrLeft, arrRight);
                long rightTree = find(nodeIndex * 2 + 1, mid + 1, nodeRight, arrLeft, arrRight);
                long result = leftTree + rightTree;
                return result;
            }
        }
    }
}

```

그래서 업데이트 연산 수를 줄여주는 lazy propagation 방식으로 구현했다.


## 고생한 점
