{literal}
<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<link rel="StyleSheet" href="/style/admin.css" type="text/css" />
	<script src="http://valums.com/files/2010/file-uploader/fileuploader.js" type="text/javascript"></script>
    <style>
		body {font-size:13px; font-family:arial, sans-serif; width:700px; margin:100px auto;}
    </style>
</head>
<body>
    <p><a href="http://github.com/valums/file-uploader">Back to project page</a></p>

	<p>To upload a file, click on the button below. Drag-and-drop is supported in FF, Chrome.</p>
	<p>Progress-bar is supported in FF3.6+, Chrome6+, Safari4+</p>

	<div id="file-uploader-demo1">
		<noscript>
			<p>Please enable JavaScript to use file uploader.</p>
			<!-- or put a simple form for upload here -->
		</noscript>
	</div>
    <script>
        function createUploader(){
            var uploader = new qq.FileUploader({
                element: document.getElementById('file-uploader-demo1'),
                action: '/upload_product_image.php',
                //action: '/admin/:filename/uploadproductimage',
                debug: true,
                onComplete: function(id, fileName, responseJSON){
                	if(responseJSON.error != null){

                	}
                },
            });
        }

        // in your app create uploader as soon as the DOM is ready
        // don't wait for the window to load
        window.onload = createUploader;
    </script>
</body>
</html>
{/literal}