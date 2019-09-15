function test(arr){
  let maxres=0;
  let time=0;
  let cur=0;
  for(let i=0;i<arr.length;++i){
      cur-=(arr[i][0]-time)>cur?cur:arr[i][0]-time;
      time=arr[i][0];
      cur+=arr[i][1];
      if(cur>maxres){
          maxres=cur;
      }
  }
  time+=cur;
  return [time,maxres];
}

let arr1=[[1,1],[2,1],[3,1]];
let arr2=[[1,3],[2,3],[3,3]];
console.log(test(arr1));
console.log(test(arr2));