function subArrayMax(nums) {
    var sum=0,value=0;
    for(let i=0;i<nums.length;++i){
        if(value<=0){
            value=nums[i];
        }else{
            value+=nums[i];
        }
        if(sum<value){
            sum=value;
        }
        
    }
    return sum;
 }

 console.log(subArrayMax([1, -2, 3, 10, -4, 7, 2, -5]));