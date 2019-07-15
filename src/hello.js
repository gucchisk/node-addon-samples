const addon = require('bindings')('addon_sample')

try {
  console.log(addon.hello())
} catch (e) {
  console.log(e)
}
