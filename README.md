# Contiki-NG-DCube: D-Cube Integration for Contiki-NG

Contiki-NG-DCube provides easy D-Cube testbed integration for [Contiki-NG](https://github.com/contiki-ng/contiki-ng), with support for the TelosB (Tmote Sky) and nrf52840 platforms currently available on D-Cube.

[D-Cube](https://iti-testbed.tugraz.at/wiki/index.php/Main_Page) is a full-fledged benchmarking infrastructure that provides a consistent way to evaluate the performance of low-power wireless systems. Hosted at Graz University of Technology, D-Cube supports around 50 nodes, with automated testing of the reliability, timeliness, and energy consumption of low-power wireless communication protocols in a variety of settings. The primary audience of D-Cube are academic researchers and industry practitioners creating low-power wireless networking solutions that would like to quantitatively assess and compare their performance with that of other systems addressing the same class of applications.

Specifically, this fork provides command-line tools to allow a user to easily post jobs to and fetch results/logs from the D-Cube testbed. This includes but is not limited to D-Cube's...

- Binary patching features for traffic pattern setup and packet injection.
- JamLab's wireless jamming facilities.
- TempLab's temperature controlled nodes.

Additionally, Contiki-NG-DCube includes a testbed service, as well as additions to Contiki-NG's deployment service, providing eeprom drivers to manage reading and writing packets from/to devices.

## Interesting Folders

- examples/dcube
- os/services/deployment
- os/services/testbed
- tools/dcube

## How to Use

To use Contiki-NG-DCube, you need to create a D-Cube account [HERE](https://iti-testbed.tugraz.at/wiki/index.php/Testbed_Access). Once you've created your account, create a new file called **key.pub** in **tools/dcube** , and add your D-Cube API key to this (either with the command below or copy ans pasting using a text editor). You can find your API key when logged into D-Cube by clicking the `dropdown menu on the top right >> API Key Management >> Show API Key`.

```
$ cd tools/dcube
$ echo "your-key-here" > key.pub
```

You'll find an example application in **examples/dcube**. This implements nullnet and simply broadcasts to nearby nodes. You can build this for either `TARGET=sky` or `TARGET=nrf52840`. The easiest way to do this and post jobs to D-Cube is through the **dcube.sh** script found in **tools/dcube**. To do this you will need to create a protocol on D-Cube, and use the protocol number assigned to it. For example, the following command will build for the skymote, and post to the testbed.

**N.B. In this example binary patching is turned off to allow simple testing of compiled binaries without D-Cube's automated testing and monitoring.**

```
$ ./dcube.sh -POST TARGET=sky -e dcube -n TEST -p <your-protocol-number> -d test_0 -nopatch
```

For a full list of commands, please use the help function.

```
$ ./dcube.sh --help
```
