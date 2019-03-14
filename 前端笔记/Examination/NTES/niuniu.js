function decrition(num,myString){
    if(myString.length!==num){
        console.log("字符串的长度不匹配");
        return false;
    }
    var left = 0,
        right = 0;
    var arr = myString.split('');
    arr.forEach(function(index,value){
        if(value==='L'){
            ++left;
        }else{
            ++right;
        }
    })
    var sub = left-right; //假设总是用向右的方向减去向左的方向
    var min = sub%4;
    switch(min)
    {
        case 0:
          return 'N';
          break;
        case 1:
          return 'E';
          break;
        case 2:
          return 'S';
          break;
        case 3:
          return 'W';
          break;
        case -1:
          return 'W';
          break;
        case -2:
          return 'S';
          break;
        case -3:
          return 'E';
          break;
    }
}

var a=decrition(3,'LRR');
console.log(a)