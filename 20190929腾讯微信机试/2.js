function superBaby(str) {
    this.sleepFirstFunc=null;
    this.sleepFunc=null;
    this.eatFunc=null;
    this.sleepFirstFunc.then(()=>{
        return this.sleepFunc;
    }).then(()=>{
        console.log("I am "+str);
    }).then(()=>{
        this.eatFunc();
    });
}
superBaby.prototype.eat=function(str){
    this.eatFunc=()=>{console.log("Eating "+str)};
}
superBaby.prototype.sleep=function(time){
    this.sleepFunc=new Promise((resolve,reject)=>{
        setTimeout(resolve, 1000*time);
    });
}
superBaby.prototype.sleepFirst=function(time){
    this.sleepFirstFunc=new Promise((resolve,reject)=>{
        setTimeout(resolve, 1000*time);
    });
}
superBaby("tom").sleepFirst(5).eat("banana")