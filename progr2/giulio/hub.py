from giulio.base_application import BaseApplication

class Hub(BaseApplication):
  def handleSwitchFeatures(self):
    # Calls all registered handlers
    super().handleSwitchFeatures()

    # handle features in hub...
    pass