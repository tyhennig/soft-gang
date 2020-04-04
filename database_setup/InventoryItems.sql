CREATE TABLE [inventory_items] (
  [id] int PRIMARY KEY IDENTITY(1, 1),
  [name] varchar(20),
  [category] varchar(10),
  [description] varchar(40),
  [active] bit,
  [imageID] int
)
GO

CREATE TABLE [inventory_attributes] (
  [attributeID] int PRIMARY KEY IDENTITY(1, 1),
  [itemID] int,
  [attribute] varchar(10),
  [quantity] int,
  [price] decimal(5,2)
)
GO

CREATE TABLE [images] (
  [itemID] int,
  [imageDescription] varchar(20),
  [imageID] int PRIMARY KEY,
  [file] varchar(20)
)
GO

CREATE TABLE [purchases] (
  [purchaseID] int PRIMARY KEY IDENTITY(1, 1),
  [customerID] int,
  [total] decimal(5,2)
)
GO

CREATE TABLE [purchaseItem] (
  [purchaseID] int,
  [attribID] int
)
GO

CREATE TABLE [customers] (
  [customerID] int PRIMARY KEY IDENTITY(1,1),
  [first] varchar(20),
  [last] varchar(20),
  [phone] varchar(15) UNIQUE,
  [email] varchar(30) UNIQUE
)
GO

ALTER TABLE [inventory_attributes] ADD FOREIGN KEY ([itemID]) REFERENCES [inventory_items] ([id])
GO

ALTER TABLE [images] ADD FOREIGN KEY ([itemID]) REFERENCES [inventory_items] ([id])
GO

ALTER TABLE [purchases] ADD FOREIGN KEY ([customerID]) REFERENCES [customers] ([customerID])
GO

ALTER TABLE [purchaseItem] ADD FOREIGN KEY ([purchaseID]) REFERENCES [purchases] ([purchaseID])
GO

ALTER TABLE [purchaseItem] ADD FOREIGN KEY ([attribID]) REFERENCES [inventory_attributes] ([attributeID])
GO
