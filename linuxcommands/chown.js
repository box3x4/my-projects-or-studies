var fs = require('fs');

fs.chown(process.argv[4],process.argv[2],process.argv[3],function(err){

	if(err){
		return console.error(err);
	}
});