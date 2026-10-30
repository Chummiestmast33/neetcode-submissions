class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map = {}
        for i in range(0, len(nums)):
            tagNum = target - nums[i];
            if(tagNum in map):
                return [map[tagNum],i]
            map[nums[i]] = i;

        return []
# Target - actual = faltante
# {numero : posicion}
# Si existe hacemos return del valor del numero y el indice
# Si no existe guardamos el valor actual        