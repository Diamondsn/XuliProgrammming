//es6
class Tree {
    constructor(size = '10', leaves = {spring: 'green', summer: 'green', fall: 'orange', winter: null}) {
      this.size = size;
      this.leaves = leaves;
      this.leafColor = null;
    }
  
    changeSeason(season) {
      this.leafColor = this.leaves[season];
      if (season === 'spring') {
        this.size += 1;
      }
    }
  }
  
  class Maple extends Tree {
    constructor(syrupQty = 15, size, leaves) {
      super(size, leaves); //super用作函数
      this.syrupQty = syrupQty;
    }
  
    changeSeason(season) {
      super.changeSeason(season);//super用作对象
      if (season === 'spring') {
        this.syrupQty += 1;
      }
    }
  
    gatherSyrup() {
      this.syrupQty -= 3;
    }
  }


  //es5
  function Tree(size, leaves) {
    this.size = size || 10;
    this.leaves = leaves || {spring: 'green', summer: 'green', fall: 'orange', winter: null};
    this.leafColor;
  }
  
  Tree.prototype.changeSeason = function(season) {
    this.leafColor = this.leaves[season];
    if (season === 'spring') {
      this.size += 1;
    }
  }
  
  function Maple (syrupQty, size, leaves) {
    Tree.call(this, size, leaves);
    this.syrupQty = syrupQty || 15;
  }
  
  //extends
  Maple.prototype = Object.create(Tree.prototype);
  Maple.prototype.constructor = Maple;
  
  Maple.prototype.changeSeason = function(season) {
    Tree.prototype.changeSeason.call(this, season);
    if (season === 'spring') {
      this.syrupQty += 1;
    }
  }
  
  Maple.prototype.gatherSyrup = function() {
    this.syrupQty -= 3;
  }