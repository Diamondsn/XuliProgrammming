function check(num){
  let arr=[];
  while(true){
      let square=get(num);
      if(square==1){
          return true;
      }
      if(arr.indexOf(square)>=0){
          return false;
      }
      arr.push(square);
      num=square;
  }
}
function get(num){
    let sum =0;
    for(;;){
        let a=num%10;
        sum+=a*a;
        num=Math.floor(num/10);
        if(num==0){
            break;
        }
    }
    return sum;
}
console.log(check(19));
console.log(check(7));