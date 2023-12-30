# MinHash-HE

### Installing Dependencies
In order to run MinHash homomorphically, we need to install some dependencies.

first, we will build the Google-XLS framework from their [GitHub repository](https://github.com/google/xls). Google-XLS depends on bazel so you need to install bazel beforehand.

```shell
sudo apt install apt-transport-https curl gnupg -y
curl -fsSL https://bazel.build/bazel-release.pub.gpg | gpg --dearmor >bazel-archive-keyring.gpg
sudo mv bazel-archive-keyring.gpg /usr/share/keyrings
echo "deb [arch=amd64 signed-by=/usr/share/keyrings/bazel-archive-keyring.gpg] https://storage.googleapis.com/bazel-apt stable jdk1.8" | sudo tee /etc/apt/sources.list.d/bazel.list

sudo apt update && sudo apt install bazel

sudo apt update && sudo apt install bazel-6.4.0
```


We run the following commands to build XLS with bazel.

```shell
git clone https://github.com/google/xls.git
cd xls

bazel --version
sudo apt install python3-distutils python3-dev libtinfo5 python-is-python3
bazel test -c opt -- //xls/...
```

now that we have builded our Google-XLS, we need to build Yosys from the [GitHub repository](https://github.com/YosysHQ/yosys).

```shell
$ sudo apt-get install build-essential clang bison flex \
	libreadline-dev gawk tcl-dev libffi-dev git \
	graphviz xdot pkg-config python3 libboost-system-dev \
	libboost-python-dev libboost-filesystem-dev zlib1g-dev

git clone https://github.com/YosysHQ/yosys.git
cd yosys
make


```

now we clone HELM from the [GitHub repository](https://github.com/TrustworthyComputing/helm/tree/main). HELM requires at least rustc version 1.72 to build. To do this first remove any lower version of rustc you have.

```shell
apt autoremove rustc
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
export PATH=~/.cargo/bin:$PATH
rustc --version
```
check if the rustc version installed is at least 1.72. Now we clone and build HELM.

```shell
git clone --recurse-submodules https://github.com/TrustworthyComputing/helm.git
cd helm
cargo build --release
```
Now that we have built all of the dependencies, we start by cloning and running this repository.

note that Yosys, XLS, and HELM builds need to be in the same directory for the scripts to work.

### How to cite this work
The [MatcHEd article](https://github.com/TrustworthyComputing/minhash-HE/blob/main/MatcHEd.pdf) that details this work can be cited as follows:

```
@misc{shokri2023MatcHEd,
    author       = {Rostin Shokri and Charles Gouert and Nektarios Georgios Tsoutsos},
    title        = {{MatcHEd: Privacy-Preserving Set Similarity based on MinHash}},
    year         = {2023},
    note         = {\url{https://github.com/TrustworthyComputing/minhash-HE/blob/main/MatcHEd.pdf}},
}
```
