class KthLargest {
    vector<int> arr;
    int size;
    int maxSize;

   public:
    KthLargest(int k, vector<int>& nums) {
        size = 0;
        maxSize = k;
        for (int num : nums) {
            addValue(num);
        }
    }

    int getParent(int i) { return (i - 1) / 2; }
    int getLeftChildren(int i) { return i * 2 + 1; }
    int getRigthChildren(int i) { return i * 2 + 2; }

    void shiftUp(int i) {
        while (i > 0 && arr[i] < arr[getParent(i)]) {
            swap(arr[i], arr[getParent(i)]);
            i = getParent(i);
        }
    }

    void shiftDown(int i) {
        int minIndex = i;
        if (getLeftChildren(i) < size && arr[minIndex] > arr[getLeftChildren(i)]) {
            minIndex = getLeftChildren(i);
        }
        if (getRigthChildren(i) < size && arr[minIndex] > arr[getRigthChildren(i)]) {
            minIndex = getRigthChildren(i);
        }
        if (i != minIndex) {
            swap(arr[i], arr[minIndex]);
            shiftDown(minIndex);
        }
    }

    int getTop() { return arr[0]; }

    void addValue(int val) {
        if (size == maxSize) {
            if (getTop() < val) {
                arr[0] = val;
                shiftDown(0);
            }
        } else {
            arr.push_back(val);
            ++size;
            shiftUp(size - 1);
        }
    }

    int add(int val) {
        addValue(val);
        return getTop(); 
    }
};
