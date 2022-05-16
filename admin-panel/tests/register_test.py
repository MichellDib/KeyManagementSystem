# import all required frameworks
import unittest
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from webdriver_manager.chrome import ChromeDriverManager
import time
# inherit TestCase Class and create a new test class
class KMS_test_class(unittest.TestCase):

    # initialization of webdriver
    def setUp(self):
        #self.driver = webdriver.Chrome()
        self.driver = webdriver.Chrome(ChromeDriverManager().install())


    # Test case method. It should always start with test_
    def tests(self):

        # get driver
        driver = self.driver
        # get python.org using selenium
        driver.get("http://localhost:3000/")

        # assertion to confirm if title has python keyword in it
        self.assertIn("TITLE", driver.title)
        time.sleep(2)


        # locate element using name
        time.sleep(2)
        fill_in_email = driver.find_element_by_xpath("//*[@id='email']").send_keys("Michell@gmail.com")
        fill_in_username =  driver.find_element_by_xpath("//*[@id='username']").send_keys("Michell")
        fill_in_pass = driver.find_element_by_xpath("//*[@id='password']").send_keys("123456")

        check_remember_me = driver.find_element_by_xpath("//*[@id='root']/main/div/form/label/span[1]/input").click()
        
        

        login = driver.find_element_by_xpath("//*[@id='root']/main/div/form/button").click()
        time.sleep(5)

        assert "SIGN UP" not in driver.page_source

    # cleanup method called after every test performed
    def tearDown(self):
        self.driver.close()

# execute the script
if __name__ == "__main__":
    unittest.main()