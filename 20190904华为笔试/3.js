function test(arr){
    let obj={};
    let result=[];
  for(let i=0;i<arr.length;++i){
      for(let j=0;j<arr[i].length;++j){
        if(arr[i][j]=="{"){
            obj["{"]=obj["{"]?obj["{"]+1:1;
        }else if(arr[i][j]=="}"){
            obj["}"]=obj["}"]?obj["}"]+1:1;
        }else if(arr[i][j]=="["){
            obj["["]=obj["["]?obj["["]+1:1;
        }else if(arr[i][j]=="]"){
            obj["]"]=obj["]"]?obj["]"]+1:1;
        }else if(arr[i][j]=='"'){
            obj["yinhao"]=obj["yinhao"]?obj["yinhao"]+1:1;
        }else if(arr[i][j]==","){
            obj[","]=obj[","]?obj[","]+1:1;
        }
      }
  }
    if (obj["{"] !== obj["}"]) {
        result.push(2);
    }
    if (obj["["] !== obj["]"]) {
        result.push(1);
    }
    if (obj["yinhao"] % 2 !== 0) {
        result.push(3);
    }
   let count=Math.max(obj["{"],obj["}"])%2-1+Math.max(obj["["],obj["]"])%2-1+Math.ceil(obj["yinhao"] % 4)-Math.max(obj["{"],obj["}"])%2;
   if(obj[","]<count){
       result.push(4);
   }

  if(result.length==0){
      result.push(0);
  }
  return result.sort().join("");
}
console.log(test);