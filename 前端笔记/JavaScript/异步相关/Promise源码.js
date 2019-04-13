function Promise(executor) {
    var self = this;
    this.status = 'pending';
    this.value = undefined;
    this.reason = undefined;
    this.onResolvedCallbacks = [];
    this.onRejectedCallbacks = [];

    function resolve(value) {
        if(self.status === 'pending') {
            self.status = 'resolve';
            self.value = value;
            self.onResolvedCallbacks.forEach(function (fn) {
                fn();
            })
        }
    }
    function reject(reason) {
        if(self.status === 'pending') {
            self.status = 'rejected';
            self.reason = reason;
            self.onRejectedCallbacks.forEach(function (fn) {
                fn();
            })
        }
    }
    executor(resolve, reject);
}

Promise.prototype.then = function (infulfilled, inrejected) {
    var self = this;
    if(this.status === 'resolve') {
        infulfilled(this.value)
    }
    if(this.status === 'rejected') {
        inrejected(this.reason)
    }
    if(this.status === 'pending') {
        this.onResolvedCallbacks.push(function () {
            infulfilled(self.value)
        });
        this.onRejectedCallbacks.push(function () {
            inrejected(self.reason)
        });
    }
};

var p = new Promise(function (resolve, reject) {
    setTimeout(function () {
        resolve('resolve');
    })
});

p.then(function (data) {
    console.log(data);
}, function (err) {
    console.log(err);
});
--------------------- 
作者：Lkkkkkkg 
来源：CSDN 
原文：https://blog.csdn.net/qq593249106/article/details/83096588 
版权声明：本文为博主原创文章，转载请附上博文链接！







// 第一步：Promise构造函数接受一个函数作为参数，该函数的两个参数分别是resolve和reject。它们是两个函数，由 JavaScript 引擎提供，不用自己部署。
function Promise(task) {

    let that = this; // 缓存this
    that.status = 'pending'; // 进行中的状态
    that.value = undefined; //初始值

    that.onResolvedCallbacks = []; // 存放成功后要执行的回调函数的序列
    that.RejectedCallbacks = []; // 存放失败后要执行的回调函数的序列
    // 该方法是将Promise由pending变成fulfilled
    function resolve (value) {
        if (that.status == 'pending') {
            that.status = 'fulfilled';
            that.value = value;
            that.onResolvedCallbacks.forEach(cb => cd(that.value))
        }

    }
    // 该方法是将Promise由pending变成rejected
    function reject (reason) {
      if (that.status == 'pending') {
            that.status = 'rejected';
            that.value = reason;
            that.onRjectedCallbacks.forEach(cb => cd(that.value))
        }
    }

    try {
    // 每一个Promise在new一个实例的时候 接受的函数都是立即执行的
        task(resolve, reject)
    } catch (e) {
        reject(e)
    }
}

// 第二部 写then方法，接收两个函数onFulfilled onRejected，状态是成功态的时候调用onFulfilled 传入成功后的值，失败态的时候执行onRejected，传入失败的原因，pending 状态时将成功和失败后的这两个方法缓存到对应的数组中，当成功或失败后 依次再执行调用
Promise.prototype.then = function(onFulfilled, onRejected) {
    let that = this;
    if (that.status == 'fulfilled') {
        onFulfilled(that.value);
    }
    if (that.status == 'rejected') {
        onRejected(that.value);
    }
    if (that.status == 'pending') {
        that.onResolvedCallbacks.push(onFulfilled);
        that.onRjectedCallbacks.push(onRejected);
    }
}