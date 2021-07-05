<?php

// api key
$keyfile = file_get_contents('./key.pub');
$key = "?key=" . $keyfile;
$key = str_replace(array("\r\n", "\n", "\r"), '', $key);
$base = "https://iti-testbed.tugraz.at/api/";

$act = "queue/create_job";

$job = array(
    "protocol"        => intval($argv[1]),
    "layout"          => $argv[2],  // NB: Bug in API means this is a str
    "periodicity"     => intval($argv[3]),
    "message_length"  => intval($argv[4]),
    "patching"        => intval($argv[5]),
    "name"            => $argv[6],
    "description"     => $argv[7],
    "duration"        => intval($argv[8]),
    "logs"            => intval($argv[9]),
    "jamming"         => intval($argv[10]),
    "priority"        => boolval($argv[11]),
    "file"            => base64_encode(file_get_contents($argv[12]))
);
if($argv[13]) {
  $job["temp_profile"] = $argv[13];
}
$overrides = array();
if($argv[14]) {
  $overrides["start"] = intval($argv[14]);
}
if($argv[15]) {
  $overrides["delta"] = intval($argv[15]);
}
if(sizeof($overrides)) {
  $job["config_overrides"] = $overrides;
}

$payload = json_encode($job);

// print_r($payload);


$options = array(
    'http' => array(
    'method'  => 'POST',
    'content' => $payload,
    'header'=>  "Content-Type: application/json\r\n"
  )
);

$context  = stream_context_create($options);

$result = file_get_contents($base . $act . $key, false, $context);
$response = json_decode($result, true);

echo "Job created, got response:" . PHP_EOL;
var_dump($result);
// print_r($response);
echo "Job ID: " . $response['id'] . PHP_EOL;

return $response['id'];
