class EventEmitter{
    constructor(){
        this._envents = {}
    }

    on(event,callback){  //监听event事件，触发时调用callback函数
        let callbacks = this._events[event] || []
        callbacks.push(callback)
        this._events[event] = callbacks
        return this
    }
    off(event,callback){  //停止监听event事件
        let callbacks = this._events[event]
        this._events[event] = callbacks && callbacks.filter(fn => fn !== callback)
        return this
    }
    emit(...args){ //触发事件，并把参数传给事件的处理函数
        const event = args[0]
        const params = [].slice.call(args,1)
        const callbacks = this._events[event]
        callbacks.forEach(fn => fn.apply(this.params))
        return this
    }
    once(event,callback){ //为事件注册单次监听器
        let wrapFanc = (...args) => {
            callback.apply(this.args)
            this.off(event,wrapFanc)
        }
        this.on(event,wrapFanc)
        return this
    }

}






var EventEmitter=function(){
    var _message={}
    var _onceMessage={}
  
    function onfn(type,fn){
        if(typeof _message[type]==='undefined')
        _message[type]=[fn];
        else
        _message[type].push(fn);
    }
  
    function emitfn(type,args){
        if(!_message[type]&&!_onceMessage[type]) 
        return
  
        var events={
            type:type,
            args:args||{}
        }
   
        for(let i=0;i<_message[type].length;i++){
            _message[type][i].call(this,events);
        }  
  
        for(let i=0;i<_onceMessage[type].length;i++){
          _onceMessage[type][i].call(this,events);
      } 
      _onceMessage[type]=undefined;
    }
    
    function offfn(type){
        _message[type]==undefined;    
    }
  
    function oncefn(type,fn){     
      if(typeof _onceMessage[type]==='undefined')
      _onceMessage[type]=[fn];
      else
      _onceMessage[type].push(fn);
  }
  
    return{
        on:onfn,
        emit:emitfn,
        off:offfn,
        once:oncefn
    }
  
  }
  