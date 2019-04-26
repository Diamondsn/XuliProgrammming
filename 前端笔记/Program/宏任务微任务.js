console.log("begin");
setTimeout(()=>{
      console.log("setTimeout1");
      Promise.resolve().then(()=>{
          console.log("promise1");
          setTimeout(()=>{
              console.log("setTimeout2");
          })
      }).then(()=>{
          console.log("promise2");
      });
},0);
console.log("end");

//begin end setTimeout1 promise1 promise2 setTimeout2


