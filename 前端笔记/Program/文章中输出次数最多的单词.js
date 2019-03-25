function test(str){
    let arr=str.split(" ");
    let obj={};
    for(let i=0;i<arr.length;++i){
         if(arr[i]!==' '||arr[i]!==','||arr[i]!=='.'||arr[i]!==''){
             if(obj[arr[i]]){
                 obj[arr[i]]++;
             }else{
                 obj[arr[i]]=1;
             }
         }
    }
    let max=0;
    let res=[];
    let count=[];
    for(item in obj){
        let key=item;
        let value=obj[key];
        if(value>max){
            res.length=0;
            count.length=0;
            res.push(key);
            count.push(value);
        }else if(value==max){
            res.push(key);
            count.push(value);
        }
        max=value>max?value:max;
    }
    return{word:res,time:count};
}

console.log(test("ab ab ab bc bc bc, . "));





//使用正则表达式
function counts(article){
    article = article.trim().toUpperCase();
    var array = article.match(/[A-z]+/g);
    article = " "+array.join("  ")+" ";
    var max = 0,word,num = 0,maxword="";
    for(var i = 0; i < array.length; i++) {        
        word = new RegExp(" "+array[i]+" ",'g');
    num = article.match(word).length;
    if(num>max){
        max=num;
        maxword = array[i];
    }
   }
   console.log(maxword+" "+max);
}
counts("Age has reached the end of the beginning of a word. May be guilty in his seems to passing a lot of different life became the appearance of the same day;");



//另解
function test1(str){
    var arr=str.split(/[,.; ]/);
    let obj={};
    for(let i=0;i<arr.length;++i){
         if(arr[i]!==' '||arr[i]!==','||arr[i]!=='.'||arr[i]!==''){
             if(obj[arr[i]]){
                 obj[arr[i]]++;
             }else{
                 obj[arr[i]]=1;
             }
         }
    }
    let max=0;
    let res=[];
    let count=[];
    for(item in obj){
        let key=item;
        let value=obj[key];
        if(value>max){
            res.length=0;
            count.length=0;
            res.push(key);
            count.push(value);
        }else if(value==max){
            res.push(key);
            count.push(value);
        }
        max=value>max?value:max;
    }
    return{word:res,time:max};
}

console.log(test1("Age has reached the end of the beginning of a word. May be guilty in his seems to passing a lot of different life became the appearance of the same day;"));