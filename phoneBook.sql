CREATE DATABASE IF NOT EXISTS phonebook_db;
USE phonebook_db;
CREATE TABLE IF NOT EXISTS contacts (
  name VARCHAR(100),
  number VARCHAR(20),
  email VARCHAR(100)
);

INSERT INTO contacts (name, number, email) VALUES
('Eugene Krabs', '982-347-8790', 'notTheSecretForumla@yahoo.com'),
('Patrick Star', '892-345-7890', 'rockbottom@gmail.com'),
('SpongeBob SquarePants', '875-234-7865', 'squary@outlook.com'),
('Squidward Tentacles', '894-237-3890', 'Iloveclarinets@gmail.com');
