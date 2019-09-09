function findTree(set,map,num){
  if(map[num]){
      for(let j=0;j<map[num].length;++j){
          set.add(map[num][j]);
          findTree(set,map,map[num][j]);
      }
    }else{
        set.add(num);
    }
}

function test(arr1,arr2,num){
   let map={};
   for(let i=0;i<arr2.length;++i){
       if(!map[arr2[i]]){
           map[arr2[i]]=[arr1[i]];
       }else{
        map[arr2[i]].push(arr1[i]);
       }
   }
   if(!map[num])return 1;
   else{
    let set=new Set();
    findTree(set,map,num);
    console.log(set);
       return set.size+1;
   }
}

let arr1=[3,1,5,21,10];
let arr2=[0,3,3,1,5];
let num=3;
console.log(test(arr1,arr2,num));