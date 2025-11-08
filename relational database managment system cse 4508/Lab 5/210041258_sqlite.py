from sqlalchemy.orm import sessionmaker
from sqlalchemy import create_engine, Column, Integer, String, Float
from sqlalchemy.ext.declarative import declarative_base



# creation of the session is important 
# i see that the session is created and commit each time 
# i see also that table on createion with attrubute initalization on __tablename__ = 'books' as branch on the  database
# i relise the  use of the declarative_base() function to create a base class for declarative class definitions
# i see that the use of the Column() function to define the columns of the table
# i see that the use of the Integer, String, Float to define the type of the columns and of curse the nullable attrubute and the nulablity of each column defined
# i also make the stauts of the book to check the operation of the book to confirm the operation side becuase on sqllite i configure that
# it depneds on extra data showen up on it which its musn't be appered on the output 
# i added on it  to be showen for any one will see the code so on  






engine = create_engine('sqlite:///books.db', echo=True)
Base = declarative_base()

class Book(Base):
    __tablename__ = 'books'
    
    id = Column(Integer, primary_key=True)
    title = Column(String, nullable=False)
    author = Column(String, nullable=False)
    published_year = Column(Integer, nullable=False)
    price = Column(Float, nullable=False)

Base.metadata.create_all(engine)

Session = sessionmaker(bind=engine)
session = Session()

book_status = {}

new_book = Book(title="The Great Gatsby", author="F. Scott Fitzgerald", published_year=1925, price=10.99)
session.add(new_book)
session.commit()
book_status[new_book.title] = 'added'

books = session.query(Book).all()
for book in books:
    status = book_status.get(book.title, 'unknown')
    print(f"Id : {book.id},Title: {book.title}, Author: {book.author}, Year: {book.published_year}, Price: {book.price}, Status: {status}")

book_to_update = session.query(Book).filter_by(title="The Great Gatsby").first()
if book_to_update:
    book_to_update.price = 12.99
    session.commit()
    book_status[book_to_update.title] = 'updated'

books = session.query(Book).all()
for book in books:
    status = book_status.get(book.title, 'unknown')
    print(f"Id : {book.id},Title: {book.title}, Author: {book.author}, Year: {book.published_year}, Price: {book.price}, Status: {status}")

book_to_delete = session.query(Book).filter_by(title="The Great Gatsby").first()
if book_to_delete:
    session.delete(book_to_delete)
    session.commit()
    book_status[book_to_delete.title] = 'deleted'

books = session.query(Book).all()
for book in books:
    status = book_status.get(book.title, 'unknown')
    print(f"Id : {book.id},Title: {book.title}, Author: {book.author}, Year: {book.published_year}, Price: {book.price}, Status: {status}")

if "The Great Gatsby" in book_status:
    print(f"Title: The Great Gatsby, Status: {book_status['The Great Gatsby']}")