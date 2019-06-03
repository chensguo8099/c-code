package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"time"

	"github.com/google/gopacket"
	"github.com/google/gopacket/pcap"
)

var (
	device       string = "wlp3s0"
	snapshot_len int32  = 1024
	promiscuous  bool   = false
	err          error
	timeout      time.Duration = 30 * time.Second
	handle       *pcap.Handle
)

func main() {
	// Open device
	handle, err = pcap.OpenLive(device, snapshot_len, promiscuous, timeout)
	if err != nil {
		log.Fatal(err)
	}
	defer handle.Close()

	//Create file and record the network information in file.txt
	// filepath := "/opt/gopath/src/chaincode/mylogsys/log/log.txt"
	filepath := "/home/chenguo/code/go/src/go_code/netcatch/main/file.txt"
	file, err := os.OpenFile(filepath, os.O_WRONLY|os.O_CREATE|os.O_APPEND, 0666)
	if err != nil {
		fmt.Printf("open err :%v\n", err)
		return
	}
	defer file.Close()
	writer := bufio.NewWriter(file)

	// Use the handle as a packet source to process all packets
	packetSource := gopacket.NewPacketSource(handle, handle.LinkType())
	for packet := range packetSource.Packets() {
		// Process packet here
		str := fmt.Sprintf("%v", packet)
		writer.WriteString(str)
		writer.Flush()
	}
}
