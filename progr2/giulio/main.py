from giulio.base_application import HandlerKind
from giulio.hub import Hub

def main():
  hub = (Hub
    .create()
    .use(HandlerKind.ArpResponder)
    .use(HandlerKind.LearningSwitch))

  hub.handleSwitchFeatures()


if __name__ == '__main__':
  main()