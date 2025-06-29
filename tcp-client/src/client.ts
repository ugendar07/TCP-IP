import * as net from 'net';
import * as readline from 'readline';

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const client = new net.Socket();

client.connect(8080, '127.0.0.1', () => {
  console.log('Connected to server');
  rl.setPrompt('Enter command: ');
  rl.prompt();

  rl.on('line', (line: string) => {
    client.write(line + '\n');
    rl.prompt();
  });
});

client.on('data', (data) => {
  console.log('From server:', data.toString().trim());
});

client.on('close', () => {
  console.log('Connection closed');
  rl.close();
});

client.on('error', (err) => {
  console.error('Socket error:', err.message);
  rl.close();
});
