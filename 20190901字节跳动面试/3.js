function test(arr){
    for(var i=0;i<arr.length;++i){
        setTimeout((function(index){
            return function(){
                console.log(index);
            }
        })(i),1000*i);
    }
}