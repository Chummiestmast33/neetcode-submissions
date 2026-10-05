class Solution {
    int maxQuantity;
    vector<vector<int>> arr;
    int size;
    int kSize;

   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        size = 0;
        kSize = k;
        for (vector<int> vec : points) {
            add(vec);
        }
        return arr;
    }

    double calculateDistance(vector<int> point) {
        return sqrt(pow(0 - point[0], 2) + pow(0 - point[1], 2));
    }

    int getParent(int i) { return (i - 1) / 2; }

    int getLeftChild(int i) { return i * 2 + 1; }

    int getRightChild(int i) { return i * 2 + 2; }

    void shiftUp(int i) {
        while (i > 0 && calculateDistance(arr[getParent(i)]) < calculateDistance(arr[i])) {
            swap(arr[i], arr[getParent(i)]);
            i = getParent(i);
        }
    }

    void shiftDown(int i) {
        int maxIndex = i;
        if (getLeftChild(i) < size &&
            calculateDistance(arr[maxIndex]) < calculateDistance(arr[getLeftChild(i)])) {
            maxIndex = getLeftChild(i);
        }
        if (getRightChild(i) < size &&
            calculateDistance(arr[maxIndex]) < calculateDistance(arr[getRightChild(i)])) {
            maxIndex = getRightChild(i);
        }
        if (maxIndex != i) {
            swap(arr[maxIndex], arr[i]);
            shiftDown(maxIndex);
        }
    }

    vector<int> getTop() {
        vector<int> point = arr[0];
        swap(arr[0], arr[size - 1]);
        arr.pop_back();
        --size;
        shiftDown(0);
        return point;
    }

    vector<int> top() { return arr[0]; }

    void add(vector<int> point) {
        if (size < kSize) {
            arr.push_back(point);
            ++size;
            shiftUp(size - 1);
        } else {
            if (calculateDistance(point) < calculateDistance(arr[0])) {
                arr[0] = point;
                shiftDown(0);
            }
        }
    }
};
