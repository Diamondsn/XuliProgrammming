let count=0;
function compute(n,k){
    if(n<=k){count++;return;}
  if((n+k)%2==0&&(n-k)%2==0){
      compute(Math.floor((n+k)/2),k);
      compute(Math.floor((n-k)/2),k);
  }else{
      count++;
  }
}

function test(n,k){
  compute(n,k);
  return count;
}

console.log(test(10,2));