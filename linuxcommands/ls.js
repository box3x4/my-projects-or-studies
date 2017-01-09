var fs = require('fs');

//var path = process.argv[2];


fs.readdir(process.argv[2], function(err,files){

	if(err){
		return console.error(err);
	}

	files.forEach(function(file){
		console.log(file);
	});
});