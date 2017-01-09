var fs = require('fs');
var buf = new Buffer(2048);

fs.open(process.argv[2],'r+',function(err,fd){

	if(err){
		return console.error(err);
	}

	fs.read(fd,buf,0,buf.length,0,function(err,bytes){

		if(err){
			return console.error(err);
		}

		if(bytes > 0){
			console.log(buf.slice(0,bytes).toString());
		}

		fs.close(fd, function(err){

			if(err){
				return console.error(err);
			}
		})
	})
})