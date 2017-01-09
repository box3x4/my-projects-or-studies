var fs = require('fs');

fs.mkdir(process.argv[2],function(err){

	if(err){
		return console.error(err);
	}
});