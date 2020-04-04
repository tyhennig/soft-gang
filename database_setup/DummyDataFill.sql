
INSERT INTO customers (first,last,phone,email)
VALUES ('tyler','hennig','9794802488','tyhennig@gmail.com'),
('joe','mama','2465132468','mamajoenus@gmail.com'),
('michael','scott','2631569825','mscott234@yahoo.com'),
('oscar','martinez','4925161234','ossimart@gmail.com');

INSERT INTO inventory_items (name,category,description,active)
VALUES ('porky shirt', 'shirt', 'a blue porky shirt', 1),
('A&I Logo shirt', 'shirt', 'a grey logo shirt', 1),
('alumni shirt', 'shirt', 'white alumni shirt', 1);


INSERT INTO inventory_attributes (itemID,attribute,quantity,price)
VALUES (1,'small', 13, 15.00),
(1,'medium', 3, 15.00),
(1,'large', 16, 20.00),
(2,'small', 4, 15.00),
(2,'medium',6,15.00),
(2,'large',8,20.00),
(3,'small', 9, 15.00),
(3,'medium',11,15.00),
(3,'large',20,20.00);

INSERT INTO purchases(customerID,total)
VALUES (1,30.00),(2,15.00),(3,35.00);

INSERT INTO purchaseItem(purchaseID, attribID)
VALUES (1, 1), (1,2), (2,5), (3,5),(3,6);
