var exec = require('child_process').exec;
exec('cp nwrfcsdk/lib/* build/Release', function(error,stdout,sterr){
    if(error!=null)
        console.log(error);
    else
        console.log('success');
});