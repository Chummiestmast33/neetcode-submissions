class Solution {
   public:
    vector<int> arr;
    int size;
    int lastStoneWeight(vector<int>& stones) {
        size = 0;
        for (int stone : stones) {
            add(stone);
        }
        while (size > 1) {
            smashStones();
        }
        return arr[0];
    }
    int getParent(int i) { return (i - 1) / 2; }
    int getLeftChild(int i) { return i * 2 + 1; }
    int getRigthChild(int i) { return i * 2 + 2; }
    void shiftUp(int i) {
        while (i > 0 && arr[i] > arr[getParent(i)]) {
            swap(arr[i], arr[getParent(i)]);
            i = getParent(i);
        }
    }
    void shiftDown(int i) {
        int maxSize = i;
        if (getLeftChild(i) < size && arr[maxSize] < arr[getLeftChild(i)]) {
            maxSize = getLeftChild(i);
        }
        if (getRigthChild(i) < size && arr[maxSize] < arr[getRigthChild(i)]) {
            maxSize = getRigthChild(i);
        }
        if (i != maxSize) {
            swap(arr[i], arr[maxSize]);
            shiftDown(maxSize);
        }
    }
    void add(int i) {
        arr.push_back(i);
        ++size;
        shiftUp(size - 1);
    }
    int extractMax() {
        swap(arr[0], arr[size - 1]);
        int max = arr[size - 1];
        arr.pop_back();
        --size;
        shiftDown(0);
        return max;
    }
    void smashStones() {
        int firstStone = extractMax();
        int secondStone = extractMax();
        int stoneResult = firstStone - secondStone;
        arr.push_back(stoneResult);
        ++size;
        shiftUp(size - 1);
    }
};
