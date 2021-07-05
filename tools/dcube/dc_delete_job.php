<?php

// api key
$keyfile = file_get_contents('./key.pub');
$key = "?key=" . $keyfile;
$key = str_replace(array("\r\n", "\n", "\r"), '', $key);
$base = "https://iti-testbed.tugraz.at/api/";

$act = "queue/" . $argv[1];

$options = array(
    'http' => array(
    'method'  => 'DELETE',
    'header'=>  "Content-Type: application/json\r\n"
  )
);

$context  = stream_context_create($options);
$result = file_get_contents($base . $act . $key, false, $context);
$response = json_decode($result, true);

echo "Job deleted, got response:" . PHP_EOL;
echo "DELETED job with ID: " . $response['id'] . PHP_EOL;
return $response['id'];
