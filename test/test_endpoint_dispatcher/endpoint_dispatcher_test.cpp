#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "gmock/gmock-actions.h"

#include "EndpointDispatcher.h"
#include "HtmlComposer.h"

using namespace testing;

class MockDatabase : public AbstractDatabase
{
public:
    MOCK_METHOD1(add, bool(string));
    MOCK_METHOD1(remove, bool(string));
    MOCK_METHOD0(getAll, vector<string>(void));
    MOCK_METHOD0(clear, bool(void));
};

class MockComposer : public HtmlComposer
{
public:
    MOCK_METHOD0(composeSite, const char *(void));
    MOCK_METHOD0(composeGetMessages, const char *(void));
    MOCK_METHOD1(composeMessage, const char *(string));
    MOCK_METHOD2(composeAdd, const char *(string, bool));
    MOCK_METHOD2(composeRemoved, const char *(string, bool));
};

TEST(dispatcher, getMsgs)
{
    //given
    EndpointDispatcher *dispatcher = new EndpointDispatcher();
    MockDatabase mockDatabase;
    MockComposer mockComposer;
    dispatcher->setDatabase(mockDatabase);
    dispatcher->setHtmlComposer(mockComposer);

    EXPECT_CALL(mockComposer, composeGetMessages())
        .Times(1)
        .WillOnce(Return("<html><body>Wiadomosci: 1, 2</body></html>"));

    //when
    const char *messages = dispatcher->getMsgs();

    //then
    ASSERT_EQ(messages, "<html><body>Wiadomosci: 1, 2</body></html>");
}

TEST(dispatcher, postMsg)
{
    EndpointDispatcher *dispatcher = new EndpointDispatcher();
    MockDatabase mockDatabase;
    MockComposer mockComposer;
    dispatcher->setDatabase(mockDatabase);
    dispatcher->setHtmlComposer(mockComposer);

    const char *messages = dispatcher->postMsg("test", true);

    EXPECT_CALL(mockDatabase, add("test"))
        .Times(1);

    EXPECT_CALL(mockComposer, composeAdd("", true))
        .Times(1)
        .WillOnce(Return("<html><body>Added msg</body></html>"));

    ASSERT_EQ(messages, "<html><body>Added msg</body></html>");
}

TEST(dispatcher, deleteMsg){
    EndpointDispatcher *dispatcher = new EndpointDispatcher();
    MockDatabase mockDatabase;
    MockComposer mockComposer;
    dispatcher->setDatabase(mockDatabase);
    dispatcher->setHtmlComposer(mockComposer);

    const char *messages = dispatcher->deleteMsg("test", true);

    EXPECT_CALL(mockDatabase, remove("test"))
        .Times(1);

    EXPECT_CALL(mockComposer, composeRemoved("", true))
        .Times(1)
        .WillOnce(Return("<html><body>Removed msg</body></html>"));

    ASSERT_EQ(messages, "<html><body>Removed msg</body></html>");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}