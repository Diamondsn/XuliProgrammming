/**
 * 第三题：输入一个整形数组，数组里有正数也有负数。数组中连续的一个 
 * 或多个整数组成一个子数组，每个子数组都有一个和。 求所有子数组的和的最大值。
 * 输入的数组为1, -2, 3, 10, -4, 7, 2, -5，和最大的子数组为3, 10, -4, 7, 2， 因此输出为该子数组的和18。
 */
function subArrayMax(nums) {
    var max=nums[0];
    for(let i=0;i<nums.length;++i){
        var sum=0;
        for(let j=i;j<nums.length;++j){
            sum+=nums[j];
            if(sum>max){
                max=sum;
            }
        }
    }
    return max;
}

console.log(subArrayMax([1, -2, 3, 10, -4, 7, 2, -5]));