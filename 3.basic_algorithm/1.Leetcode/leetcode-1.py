'''
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
'''

'''
enumerate 函数用于遍历序列中的元素以及它们的下标：
>>> for i,j in enumerate(('a','b','c')):
 print (i,j)
0 a
1 b
2 c
>>> for i,j in enumerate([1,2,3]):
 print (i,j) 
0 1
1 2
2 3
>>> for i,j in enumerate({'a':1,'b':2}):
 print (i,j)
0 a
1 b
>>> for i,j in enumerate('abc'):
 print (i,j)
0 a
1 b
2 c
'''

import datetime

class Solution(object):
    # def twoSum(self, nums, target):
    #     """
    #     :type nums: List[int]
    #     :type target: int
    #     :rtype: List[int]
    #     """
    #     hashmap = {}
    #     for ind, num in enumerate(nums):
    #         hashmap[num] = ind
    #     for i, num in enumerate(nums):
    #         j = hashmap.get(target - num)
    #         if j is not None and i != j:
    #             return [i, j]
    def twoSum(self, nums, target):
        """这样写更直观，遍历列表同时查字典"""
        """
        init dct = {}
        第一轮 i = 0 , n = 2 , dct[2] = 0
        第二轮 i = 1 , n = 7 , target - n = 2 in dct
         :return (dct[2],1)
        """
        dct = {}
        for i, n in enumerate(nums):
            print(i, n)
            if target - n in dct:
                return [dct[target - n], i]
            dct[n] = i

if __name__ == '__main__':
    nums = [2, 7, 11, 15]
    target = 9
    obj = Solution()
    start = datetime.datetime.now()
    print(obj.twoSum(nums, target))
    end = datetime.datetime.now()
    # for i, j in enumerate(('a', 'b', 'c')):
    #     print(i, j)
    print(end - start)