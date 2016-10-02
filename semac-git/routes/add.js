var mongo = require('./db');

var getAdd = function(req,res,next) {

  res.render('add');
};

var postAdd = function(req,res,next) {

  //função para adicionar no banco. usar search no nome dps se nao existir inserir
  
};

module.exports.get = getAdd;
module.exports.post = postAdd;
