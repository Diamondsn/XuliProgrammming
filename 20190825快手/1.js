function test(str1,str2){
  let arr1=str1.split(".");
  let arr2=str2.split(".");
  while(arr1.length&&arr2.length){
    let num1=parseInt(arr1.shift());
    let num2=parseInt(arr2.shift());
      if(num1>num2){
          return false;
      }else if(num1<num2){
          return true;
      }
  }
  if(!arr1.length&&!arr2.length){
      return false;
  }else if(!arr1.length&&arr2.length){
      while(arr2.length){
          let num=arr2.shift();
          if(num!="0"){
              return true;
          }
      }
      return false;
  }else if(arr1.length&&!arr2.length){
      return false;
  }
}

console.log(test("6.6.6","6.6.7"));// true
console.log(test("1","1.0"));// false
console.log(test("1","1.0.0.2"));// true
console.log(test("0.1","1.1"));// true
console.log(test("1.2","13.37"));// true