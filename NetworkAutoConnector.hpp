#ifndef NETWORKAUTOCONNECTOR
#define NETWORKAUTOCONNECTOR
#include <string>

namespace io_github_pumpkinxd_ZitNetworkAutoConnector {

class NetworkAutoConnector {
public:
  NetworkAutoConnector();
  NetworkAutoConnector(const std::string &filename);
  void saveConfig2file(const std::string &filename);
  bool isOnline();
  void updatePubkeyFromPortal();
  void fetchPortalUrlAndQuery();

  std::string getpublicKeyExponent();
  std::string getpublicKeyModulus();

private:
  std::string PortalUrl;
  std::string QueryString;

  std::string userId;
  std::string EncryptedPWD;

  std::string publicKeyExponent; // hex
  std::string publicKeyModulus;  // hex
};

} // namespace io_github_pumpkinxd_ZitNetworkAutoConnector

#endif /* NETWORKAUTOCONNECTOR */
