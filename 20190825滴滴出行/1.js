// 题目描述：
// 某公司雇有N名员工，每名员工可以负责多个项目，但一个项目只能交由一名员工负责。
// 现在该公司接到M个项目，令Ai,j表示第i名员工负责第j个项目所带来的收益，
// 那么如果项目分配得当，总收益最大是多少？

// 输入
// 第一行包含两个整数N和M，1≤N，M≤1000。
// 接下来N行，每行包含M个整数，第i行的第j个整数表示Ai,j，1≤Ai,j≤1000。

// 输出
// 输出总收益的最大值。

// 样例输入
// 3 3
// 1 3 3
// 2 2 2
// 3 2 1
// 样例输出
// 9

function test(arr){
    let count=0;
  for(let i=0;i<arr[0].length;i++){
      let project=0;
      for(let j=0;j<arr.length;++j){
          if(arr[j][i]>project){
              project=arr[j][i];
          }
      }
      count+=project;
  }
  return count;
}

let arr=[[1,3,3],[2,2,2],[3,2,1]];
console.log(test(arr));