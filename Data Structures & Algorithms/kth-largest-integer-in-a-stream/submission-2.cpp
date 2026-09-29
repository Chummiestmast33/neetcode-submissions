class KthLargest {
    vector<int> arr;  // heap
    int size = 0;
    int position;

   public:
    KthLargest(int k, vector<int>& nums) {
        position = k;
        for(int val : nums){
            addValue(val);
        }
    }

    int getParent(int i) {
        if (i == 0) return -1;
        return (i - 1) / 2;
    }

    int getLeftChild(int i) { return i * 2 + 1; }

    int getRightChild(int i) { return i * 2 + 2; }

    void pairUp(int i) {
        // check if the child position don't brake the rules
        // if the child break the rules swap the parent and child positions
        // repeat the process until there is no more parents or the rule is no braking anymore
        while (i > 0 && arr[getParent(i)] < arr[i]) {
            // swap
            swap(arr[getParent(i)], arr[i]);
            i = getParent(i);
        }
    }

    void pairDown(int i) {
        int maxIndex = i;
        // compare the left and rigth to know what is the max element and swaped
        if (getLeftChild(i) < size && arr[getLeftChild(i)] > arr[maxIndex]) {
            maxIndex = getLeftChild(i);
        }

        if (getRightChild(i) < size && arr[getRightChild(i)] > arr[maxIndex]) {
            maxIndex = getRightChild(i);
        }

        if (i != maxIndex) {
            swap(arr[maxIndex], arr[i]);
            pairDown(maxIndex);
        }
    }

    int getMax() {
        int max = arr[0];
        swap(arr[0], arr[size - 1]);
        arr.pop_back();
        --size;
        pairDown(0);
        return max;
    }

    void addValue(int val) {
        arr.push_back(val);
        pairUp(size);
        ++size;
    }

    int add(int val) {
        vector<int> aux;
        addValue(val);
        int counter = position;
        vector<int> values;
        while (counter--) {
            values.push_back(getMax());
        }
        for (int num : values) {
            addValue(num);
        }

        return values[values.size() - 1];
    }
};