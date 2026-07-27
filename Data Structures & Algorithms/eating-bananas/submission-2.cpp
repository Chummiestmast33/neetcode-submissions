class Solution {
   public:
    /**
     * 1. Find the max value in the array
     * 2. Create the limits between 0 and the max value
     * 3. Use the binary search algorimth
     * 3.1. Dividir cada pila entre el consumo y redondearlo hacia arriba
     * (En el caso de que se encuentre una se cambia el valor, y si se
     * tiene un valor anterior se debe de comprar que sea menor)
     **/
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = 0;
        for (int number : piles) {  // O(n)
            if (number > max) max = number;
        }

        int l = 1;
        int r = max;
        int result = max;
        while (l <= r) {
            int m = l + (r - l) / 2;
            long long sumH = 0;
            for (int number : piles) {
                sumH += ceil((double)number / m);
            }
            // Verificar que sumH sea menor a H
            if (sumH <= h) {
                result = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return result;
    }
};