#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "gmock/gmock-actions.h"

#include "EndpointDispatcher.h"
#include "HtmlComposer.h"

using namespace testing;

class MockDatabase : public AbstractDatabase {
    public:
        MOCK_METHOD1(add, bool(string));
        MOCK_METHOD1(remove, bool(string));
        MOCK_METHOD0(getAll, vector<string>(void));
        MOCK_METHOD0(clear, bool(void));
};

class MockComposer : public HtmlComposer {
  public:
        MOCK_METHOD0(composeSite, const char*(void));
        MOCK_METHOD0(composeGetMessages, const char*(void));
        MOCK_METHOD1(composeMessage, const char*(string));
        MOCK_METHOD2(composeAdd, const char*(string, bool));
        MOCK_METHOD2(composeRemoved, const char*(string, bool));
};

TEST(endpoint_dispatcher, get_messages){
    //given
    EndpointDispatcher *dispatcher = new EndpointDispatcher();
    MockDatabase mockDatabase;
    MockComposer mockComposer;
    dispatcher->setDatabase(mockDatabase);
    dispatcher->setHtmlComposer(mockComposer);
    EXPECT_CALL(mockDatabase, getAll())
        .Times(1);
    EXPECT_CALL(mockComposer, composeGetMessages())
        .Times(1)
        .WillOnce(Return("<html><body>Wiadomosci: 1, 2</body></html>"));

    //when
    const char* messages = dispatcher->getMsgs();

    //then
    ASSERT_EQ(messages, "<html><body>Wiadomosci: 1, 2</body></html>");
}

// TEST(endpoint_dispatcher, post_msg){
//     EndpointDispatcher *dispatcher = new EndpointDispatcher();
//     const char* messages = dispatcher->postMsg("", true);
// }

// TEST(endpoint_dispatcher, get_messages){
//     EndpointDispatcher *dispatcher = new EndpointDispatcher();
//     const char* messages = dispatcher->postMsg("", false);
// }

// TEST(endpoint_dispatcher, get_messages){
//     EndpointDispatcher *dispatcher = new EndpointDispatcher();
//     const char* messages = dispatcher->deleteMsg("", true);
// }

// TEST(endpoint_dispatcher, get_messages){
//     EndpointDispatcher *dispatcher = new EndpointDispatcher();
//     const char* messages = dispatcher->deleteMsg("", false);
// }

int main(int argc, char** argv)
{
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}