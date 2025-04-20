// function reciever(packet, callback) {
//   setTimeout(() => {
//     const rand = Math.random();

//     if (rand < 0.2) {
//       packet.status = "ACK";
//       console.log(`Packet ${packet.id} received Successfully!`);
//     } else if (rand < 0.4) {
//       packet.status = "DELAY";
//       console.log(`Packet ${packet.id} got delayed. Retransmit requested.`);
//     } else {
//       packet.status = "NACK";
//       if (packet.rt >= 3) {
//         console.log(`Packet ${packet.id} has reached the maximum number of allowed retransmissions: ${packet.rt}. This packet will not be retransmitted.`);
//       } else {
//         packet.rt++;
//         console.log(`Packet ${packet.id} found with errors. Retransmit requested.`);
//       }
//     }

//     callback(packet.status);
//   }, 1000);
// }

// function sendPackets(packet, callback) {
//   console.log(`Sending packet ${packet.id}...`);
//   reciever(packet, (status) => {
//     if (status === "ACK") {
//       console.log(`Packet ${packet.id} acknowledged!\n`);
//       callback();
//     } else if (status === "DELAY") {
//       console.log(`Packet ${packet.id} delayed. Retransmitting...`);
//       setTimeout(() => {
//         console.log(`Retransmitted packet ${packet.id} Successfully!\n`);
//         callback();
//       }, 2000);
//     } else if (status === "NACK") {
//       if (packet.rt >= 3) {
//         console.log(`Skipping retransmission for Packet ${packet.id}.\n`);
//         callback();
//       } else {
//         console.log(`Packet ${packet.id} transmitted with errors. Retransmitting...`);
//         setTimeout(() => {
//           console.log(`Packet ${packet.id} Retransmitted Successfully!\n`);
//           sendPackets(packet, callback); // re-transmit
//         }, 2000);
//       }
//     }
//   });
// }

// function startTransmission(packets, index = 0) {
//   if (index < packets.length) {
//     sendPackets(packets[index], () => {
//       startTransmission(packets, index + 1);
//     });
//   } else {
//     console.log("All packets processed.\n");
//   }
// }

// let packets = [
//   { id: 1, content: "Attack tonight", status: "DEFAULT", rt: 0 },
//   { id: 2, content: "attack cancel", status: "DEFAULT", rt: 0 },
//   { id: 3, content: "new plan", status: "DEFAULT", rt: 0 },
//   { id: 4, content: "no attack", status: "DEFAULT", rt: 0 },
//   { id: 5, content: "shanti jindabaad", status: "DEFAULT", rt: 0 },
// ];

// startTransmission(packets);
let totalRetransmits = 0;

function receiver(packet, callback) {
  setTimeout(() => {
    const rand = Math.random();

    if (rand < 0.6) {
      packet.status = "ACK";
      console.log(`Packet ${packet.id} received successfully!`);
    } else if (rand < 0.8) {
      packet.status = "DELAY";
      console.log(`Packet ${packet.id} got delayed. Retransmit requested.`);
    } else {
      packet.status = "NACK";
      console.log(`Packet ${packet.id} found with errors. Retransmit requested.`);
    }

    callback(packet.status);
  }, 1000);
}

function sendPackets(packet, callback) {
  console.log(`Sending packet ${packet.id} (attempt ${packet.rt + 1})...`);

  receiver(packet, (status) => {
    if (status === "ACK") {
      console.log(`Packet ${packet.id} acknowledged!\n`);
      callback();
    } else {
      packet.rt++;
      totalRetransmits++;

      if (packet.rt >= 3) {
        console.log(`Packet ${packet.id} failed after ${packet.rt} attempts. Dropped.\n`);
        callback();
      } else {
        console.log(`Retransmitting packet ${packet.id}...`);
        setTimeout(() => {
          sendPackets(packet, callback);
        }, 2000);
      }
    }
  });
}

function startTransmission(packets, index = 0) {
  if (index < packets.length) {
    sendPackets(packets[index], () => {
      startTransmission(packets, index + 1);
    });
  } else {
    console.log("All packets processed.");
    console.log(`Total retransmissions: ${totalRetransmits}`);
  }
}

let packets = [
  { id: 1, content: "Attack tonight", status: "DEFAULT", rt: 0 },
  { id: 2, content: "Attack cancel", status: "DEFAULT", rt: 0 },
  { id: 3, content: "New plan", status: "DEFAULT", rt: 0 },
  { id: 4, content: "No attack", status: "DEFAULT", rt: 0 },
  { id: 5, content: "Shanti Zindabaad", status: "DEFAULT", rt: 0 },
];

startTransmission(packets);
