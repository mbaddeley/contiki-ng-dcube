<?php

// api key
$keyfile = file_get_contents('./key.pub');
$key = "?key=" . $keyfile;
$key = str_replace(array("\r\n", "\n", "\r"), '', $key);
$base = "https://iti-testbed.tugraz.at/api/";

$act = "queue/" . $argv[1];

$options = array(
    'http' => array(
    'method'  => 'GET',
    'header'=>  "Content-Type: application/json\r\n"
  )
);

$context  = stream_context_create($options);
$result = @file_get_contents($base . $act . $key, false, $context);

if($result === FALSE) {
  // NB: We read the stdout in the bash to get the description, so we can't
  //     echo the error here.
  // $error = error_get_last();
  // echo "HTTP request failed. Error was: " . $error['message'];
  echo "";
} else {
  $response = json_decode($result, true);
  $description = str_replace(",","",$response['description']);
  echo $description;
}
