class TradeAnalyzer:
    def __init__(self):
        self.instruments = {}  # Key: InstrumentID, Value: Latest price
        self.trades = {}  # Key: InstrumentID, Value: List of trades
        # Each trade is represented as a dictionary with keys: trade_id, buy_sell, price, volume, loss_per_lot

    def process_trade(self, trade_id, instrument_id, buy_sell, price, volume):
        # If the instrument is not in the dictionary, initialize it
        if instrument_id not in self.trades:
            self.trades[instrument_id] = []

        # Determine the latest price of the instrument
        latest_price = self.instruments.get(instrument_id, None)

        # If the latest price is available, calculate the loss_per_lot
        loss_per_lot = 0
        if latest_price is not None:
            loss_per_lot = ((price - latest_price) if buy_sell == 'SELL' else (latest_price - price)) * volume / volume

        # Append the trade to the list
        self.trades[instrument_id].append({
            'trade_id': trade_id,
            'buy_sell': buy_sell,
            'price': price,
            'volume': volume,
            'loss_per_lot': loss_per_lot
        })

    def process_price_update(self, instrument_id, price):
        # Update the latest price for the instrument
        self.instruments[instrument_id] = price

        # Update the loss_per_lot for all trades of this instrument
        for trade in self.trades.get(instrument_id, []):
            trade['loss_per_lot'] = ((trade['price'] - price) if trade['buy_sell'] == 'SELL' else (price - trade['price'])) * trade['volume'] / trade['volume']

    def output_worst_trade(self, instrument_id):
        worst_trade_id = None
        worst_loss_per_lot = 0

        for trade in self.trades.get(instrument_id, []):
            if trade['loss_per_lot'] < worst_loss_per_lot:
                worst_loss_per_lot = trade['loss_per_lot']
                worst_trade_id = trade['trade_id']

        if worst_trade_id is None:
            return "NO BAD TRADES"
        else:
            return str(worst_trade_id)

# Sample Case
trade_analyzer = TradeAnalyzer()
trade_analyzer.process_price_update('Google', 100)
trade_analyzer.process_trade(1, 'Google', 'BUY', 100, 10)
print(trade_analyzer.output_worst_trade('Google'))
trade_analyzer.process_trade(2, 'Google', 'SELL', 102, 5)
trade_analyzer.process_trade(3, 'Google', 'SELL', 103, 5)
trade_analyzer.process_price_update('Google', 98)
print(trade_analyzer.output_worst_trade('Google'))
trade_analyzer.process_trade(4, 'Google', 'BUY', 101, 10)
trade_analyzer.process_trade(5, 'Google', 'BUY', 100, 10)
print(trade_analyzer.output_worst_trade('Google')) 
