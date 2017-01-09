var fs = require('fs');

fs.chmod(process.argv[3],process.argv[2],function(err){

	if(err){
		return console.error(err);
	}

});