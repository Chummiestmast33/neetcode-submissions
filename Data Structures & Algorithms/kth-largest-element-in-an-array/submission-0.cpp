class Solution {
    vector<int> arr;
    int size;
    int kSize;

   public:
    int findKthLargest(vector<int>& nums, int k) {
        size = 0;
        kSize = k;
        for (int num : nums) {
            add(num);
        }
        return getTop();
    }

    int getParent(int i) { return (i - 1) / 2; }
    int getLeftChild(int i) { return i * 2 + 1; }
    int getRightChild(int i) { return i * 2 + 2; }

    void shiftDown(int i) {
        int minValue = i;
        if (getLeftChild(i) < size && arr[minValue] > arr[getLeftChild(i)]) {
            minValue = getLeftChild(i);
        }
        if (getRightChild(i) < size && arr[minValue] > arr[getRightChild(i)]) {
            minValue = getRightChild(i);
        }
        if (minValue != i) {
            swap(arr[i], arr[minValue]);
            shiftDown(minValue);
        }
    }

    void shiftUp(int i) {
        while (i > 0 && arr[getParent(i)] > arr[i]) {
            swap(arr[getParent(i)], arr[i]);
            i = getParent(i);
        }
    }

    void add(int number) {
        if (size < kSize) {
            arr.push_back(number);
            ++size;
            shiftUp(size - 1);
        } else {
            if (arr[0] < number) {
                arr[0] = number;
                shiftDown(0);
            }
        }
    }

    int getTop() { return arr[0]; }
};
