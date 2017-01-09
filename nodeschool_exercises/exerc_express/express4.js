var express = require('express');
var app = express();
var bodyparser = require('body-parser');

app.use(bodyparser.urlencoded({extended: false}));

app.post('/form', function http(req,res){

	var resp = req.body.str.split('').reverse().join('');

	res.end(resp);

}).listen(process.argv[2]);