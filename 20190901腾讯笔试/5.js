function test(bianhao,price,caozuo){
    for(let i=0;i<caozuo.length;++i){
       let index=bianhao.indexOf(caozuo[i]);
       bianhao.splice(index,1);
    }
    return bianhao.length>0?[bianhao[bianhao-length-1],price[price.length-1]]:[0,0];
}

function test2(bianhao,price,caozuo){
    let zhaungtai=[];
    for(let i=0;i<bianhao.length;++i){
        zhaungtai[i]=false;
    }


    for(let i=1;i<bianhao.length;++i){
        if(caozuo.indexOf(bianhao[i])>=0){
            zhaungtai[i]=true;
        }
    }

    let num=-1;
    for(let i=bianhao.length-1;i>=0;--i){
       if(!zhaungtai[i]){
          num=i;
          for(let j=i-1;j>=0;--j){
              if(bianhao[j]==binahao[num]){
                  num=j;
              }else{
                  return [bianhao[num],price[num]];
              }
          }
       }
    }

    if(num==-1){
        return [0,0];
    }else{
        return [bianhao[num],price[num]];
    }
}

console.log(test2([1,1],[2,2],[1]));